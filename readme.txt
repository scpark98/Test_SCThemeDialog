

[OnPaint()�� OnEraseBkgnd() ó�� ����]
- CSCThemeDlg::OnPaint()���� Ÿ��Ʋ�ٸ� �׷������� �� �Լ��� ����ϸ�
  derived class�� OnPaint()���� �׸��� �׷��� ǥ�õ��� �ʴ´�.
  �ϴ� CSCThemeDlg::OnPaint()�� �ϴ� ���� CSCThemeDlg::OnErageBkgnd()���� �ϴ�
  derived class�� OnPaint()������ �� �׷����� deactive �� �� �� ���� ��Ÿ���� ��� �츦 ���ֱ� ����
  derived class�� OnActivate()���� timer�� ����Ͽ� Invalidate() ������
  CSCThemeDlg::OnActivate()���� Invalidate()�� ȣ���Ͽ� ó����.

