

[OnPaint()�� OnEraseBkgnd() ó�� ����]
- CSCThemeDlg::OnPaint()���� Ÿ��Ʋ�ٸ� �׷������� �� �Լ��� ����ϸ�
  derived class�� OnPaint()���� �׸��� �׷��� ǥ�õ��� �ʴ´�.
  �ϴ� CSCThemeDlg::OnPaint()�� �ϴ� ���� CSCThemeDlg::OnErageBkgnd()���� �ϴ�
  derived class�� OnPaint()������ �� �׷����� deactive �� �� �� ���� ��Ÿ���� ��� �츦 ���ֱ� ����
  derived class�� OnActivate()���� timer�� ����Ͽ� Invalidate() ������
  CSCThemeDlg::OnActivate()���� Invalidate()�� ȣ���Ͽ� ó����.

[TitleBar ���� ���� ����]
1. �׻� Ÿ��Ʋ�ٰ� ǥ�õǴ� ��Ÿ��

2. ��ü ȭ�鿡���� Ÿ��Ʋ�ٰ� ǥ�õ��� �ʰ� ���콺�� �������߸� ǥ�õǴ� ��Ÿ��

- �� �ΰ��� ��� �����ϱ� ���ؼ��� WS_CAPTION�� �������� ǥ���ϰų� ����� �Ѵ�.
  �׷��߸� �ٸ� child���� Ÿ��Ż�� ������ ���� ��ġ�� �ڵ� �����ȴ�.

* �켱 �� Ŭ������ ����ϴ� ���α׷����� �����Ƿ� ���� �۾��� �����ؾ� �Ѵ�. ��� �����Ѵ�.